array :# <itemType>(
	asyncMap<resultType> :# (block : required#(itemType)resultType) # tasks<array<resultType>> {
		itemResult :# <resultType>(
			start : required#int
			items : required#array<resultType>
		)

		tasks : tasks<array<resultType>>, (
			items : length, 
			value : array<resultType>(length)
			done :# (value, result) {
				value.setarray(result.start, result.items)
			}
		)

		for(0, scheduler.idealTasks) (i) {
			start : i * length / scheduler.idealTasks
			end : (i + 1) * length / scheduler.idealTasks
			items : subarray(start, end)
			tasks.set(i, {			
				itemResult(start, items.map<resultType>(block))
			})
		}

		tasks
	}

	// block operation must be associative since this is not processed in order
	asyncCombine :# (block'(itemType, itemType)itemType) {
		tasks : tasks<itemType>, (
			items : length, 
			value : empty#itemType
			done : (value, result) {
				if (value == empty) {
					value = result
				} else {
					value = block(value, result)
				}
			}
		)

		for(0, scheduler.idealTasks) (i) {
			start : i * length / scheduler.idealTasks
			end : (i + 1) * length / scheduler.idealTasks
			items : subarray(start, end)
			tasks.set(i, {			
				items.reduce<itemType>(block)
			})
		}

		tasks		
	}
)