class foo() { this }

heap_y'heap foo : foo()
stack_y'stack foo : foo()
local_y'local foo : foo()

heap_x2'heap foo : stack_y					// fail
heap_x3'heap foo : local_y 					// fail
stack_x2'stack foo : heap_y    				// fail
stack_x4'stack foo : local_y   				// fail
