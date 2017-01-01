task<t#object> :# (
	block : required#()t
	done : empty#?(t)
	isDone = false
	value = empty#?object
	taskId = 0

	result :# () {
		// wait on lock
		if (!isDone) {
			scheduler.mainLoop(waitForTaskIds: [this.taskId])
		}
		// retrieve result & return
		value
	}
) {
	// put task on another thread
	taskId = scheduler.run(this)
	this
)

tasks<valueType, resultType> :# (
	taskIds = empty#?array<int>
	value = empty#?valueType
	done : empty#?(valueType, resultType)
	doneCount = 0

	add :# (block : required#()resultType) {
		// put task on another thread
		taskIds.add(scheduler.run(task(block, (result'resultType) {
			done(value, result)
			doneCount++
		})))
	}
	
	set :# (index : 0, block : required#()resultType) {
		// put task on another thread
		taskIds.set(index, scheduler.run(task(block, (result'resultType) {
			if (done != empty) {
				done(value, result)
			}
			doneCount++
		})))
	}

	result :# () {
		// wait on lock
		if (doneCount != taskIds.length) {
			scheduler.mainLoop(waitForAllTasks = true, waitForTaskIds = taskIds)
		}
		// retrieve result & return
		value
	}	
)

scheduler : (
	// global queue for all scheduled tasks
	sharedQueueId : asyncQueue.create('scheduler')
	// queue for handling responses on this thread
	resultQueueId : asyncQueue.create()
	queueIds : [sharedQueueId, resultQueueId]
	queues : hash<int, (object)>()
	nextId = 0
	pendingTasks : hash<int, task<>>()
	waitForAllTasks = false
	waitForTaskIds = empty#?<int>[]

	run :# (task : required#task<>, destQueueId : sharedQueueId) : int {
		taskId: nextId++
		pendingTasks.add(taskId, task)
		taskData: taskData(
			taskId: taskId,
			callerQueueId: resultQueueId,
			block: task.block
		)
		asyncQueue.queue(destQueueId, reflection.serialize(taskData))
		taskId
	}

	mainLoop :# (waitForAllTasks = false, waitForTaskIds = empty#?array<int>) {
		this.waitForAllTasks = waitForAllTasks
		this.waitForTaskIds = waitForTaskIds
		continue = true
		while(continue) {
			queueId: asyncQueue.wait(queueIds)
			data: reflection.deserialize(asyncQueue.dequeue(queueId))			
			block: queues.find(queueId)
			continue:= block(data)
		}
	}

	add :# (queueId : 0, block : empty#(object)) {
		queueIds.add(queueId)
		queues.add(queueId, block)
	}

	taskResult :# (
		taskId : 0
		value : empty#object
	)

	taskData :# (
		taskId : 0
		callerQueueId : 0
		block : empty#()object
	)
) {
	add(resultQueueId, (result) {
		task : pendingTasks.get(result.taskId)
		task.value = result.value
		task.done(result.value)
		pendingTasks.remove(result.taskId)

		if (waitForTaskIds != empty && waitForTaskIds.contains(result.taskId)) {
			if (waitForAllTasks) {
				waitForTaskIds.remove(result.taskId)
				waitForTaskIds.length != 0
			}
		} {
			true
		}	
	})

	add(sharedQueueId, (taskData) {
		result : taskResult(
			taskId : taskData.taskId
			value : taskData.block()
		)
		// get queueid for t.callerThreadId
		shareData.queue(taskData.callerQueueId, result)
		true
	})
}

-- Usage
t : task({
	// do something slow
}, (result) {
	// handle result
})

// wait for task to complete
r : t.result