#surface(
	fillRect(rect : 'rect, color: 'color)'void
)

htmlCanvas2d #surface(
	ctxVarName : "sjCTX"

	fillRect(rect : 'rect, color: 'color) {
		console.write("fillRect")
		colorText : color.asString()
		c{
			EM_ASM_({
			debugger;
				var ctx = window[UTF8ToString($0)];
				ctx.fillStyle = UTF8ToString($5);
				ctx.fillRect($1, $2, $3, $4);
			}, _parent->ctxVarName->data, rect->x, rect->y, rect->w, rect->h, colorText->data);
		}c
	}
) { 
	c{
		EM_ASM({
			var canvas = document.getElementById("canvas");
			var ctx = canvas.getContext('2d');
			window[UTF8ToString($0)] = ctx;
		}, _this->ctxVarName->data);
	}c 
	this 
}