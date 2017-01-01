type :# (
	baseType : required#?type
	immutableFields : required#array<field>
	mutableFields : required#array<field>
	result : required#?type
	name : required#string

	derived :# (baseType#type)bool
	run :# (params : array<object>)object
	field :# (
		name : required#string
		type : required#type
		default : required#object
		offset : required#int // offset in bytes from this pointer to get value
	)
)

// system functions
reflection : (
	find :# (name : required#string)type
	copy :# <type>(a : required#type)
	serialize :# (a : required#object)blob
	deserialize :# (a: required#blob)object
)

