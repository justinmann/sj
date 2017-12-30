include "lib/ui/ui.sj"

include "nau/init.sj"
include "nau/menuController.sj"
include "nau/fieldController.sj"
include "nau/forestController.sj"
include "nau/fieldScene.sj"
include "nau/forestScene.sj"
include "nau/menuScene.sj"
include "nau/nauScene3dElement.sj"
include "nau/leafPanel.sj"
include "nau/peoplePanel.sj"
include "nau/personElement.sj"
include "nau/mainPanel.sj"

root = menuElement

log.minLevel = logLevel.trace

// mainLoop_showFPS = true
// windowRender_disableVSync()

runLoop()