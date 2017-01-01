--- sj version
html(title = 'hello world') [
	body [
		div(onClick = { showMessage('hi') })
	]
]

--- html version
<html>
	<head>
		<title>hello world</title>
	</head>
	<body>
		<div>
			<button onClick="function { showMessage('hi') }" />
		</div>
	</body>
</html>