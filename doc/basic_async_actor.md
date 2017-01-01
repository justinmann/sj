stage : (
	find :# (queueId : required#int) {
		actors.find(queueId)
	}

	register :# (queueId : required#int, a : required#actor) {
		actors.add(queueId, a)
		scheduler.add(queueId, (taskData) {
			result: taskData.block()
			shareData.queue(taskData.callerQueueId, result)
		})
	}

	actors : hash<int, actor>()
)

actor :# (	
	queueId = 0
	op! :# (data : required#object)task {

	}

	send :# (data : required#object, result : empty#()object) {
		t: task(() {
			a : stage.find(queueId)
			a.run(data)
		}, result)
		scheduler.run()
		t
	}
) {
	if (queueId == 0) {
		queueId = asyncQueue.create()
		a : this
		scheduler.run(task(() {
			stage.register(queueId, a)
		}))
	}
}

-- usage

bob :# actor(
	run :# (data) {
		// process message
	}
) 

bob : bob()
bob.send(1, (result) {
	// process result
})
// or
bob!1
