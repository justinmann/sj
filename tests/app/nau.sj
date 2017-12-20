include "lib/common/common.sj"
include "lib/ui/ui.sj"
include "nau/nauScene3dElement.sj"
include "nau/leafPanel.sj"
include "nau/peoplePanel.sj"
include "nau/personElement.sj"
include "nau/fieldScene.sj"
include "nau/mainPanel.sj"
include "nau/menuScene.sj"

// nauScene : fieldScene()
nauScene : menuScene()

root : fillElement(
	children : [
		heap nauScene as #element
		heap crossHairsElement(
			color : colors.red()
		) as #element
	]
) as #element

runLoop()