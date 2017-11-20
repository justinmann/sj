foo() { this }

heap_y'heap foo : foo()
stack_y'stack foo : foo()
local_y'local foo : foo()

heap_x1'heap foo : heap_y					// x = y; x->_refCount++
heap_x4'heap foo :copy stack_y				// copy y

stack_x1'stack foo : stack_y   				// x = y or x = copy(y) if y is lower scope than x
stack_x3'stack foo :copy heap_y 			// copy y

local_x1'local foo : heap_y 				// okay
local_x2'local foo : stack_y 				// okay
local_x3'local foo : local_y 				// okay