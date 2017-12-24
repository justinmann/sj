forestController(
    selectPerson(id : 'string) {
        debug.writeLine("personElement pressed")      
        ifValid m : modelsById[id] {
            c : m.getCenter()
            w : m.getWorld()
            l : w * c.asVec4()
            d : l.asVec3()

            debug.writeLine(c.asString() + " => " + l.asString() + " & " + d.asString())

            forestScene.animateLookAt(d, 2000)

            e : heap fadeEffect()
            e.alpha = 0.0f
            e.animateAlpha(1.0f, 2000)
            forestBuyElement.effect = e as #effect

            void
        } elseEmpty {
            debug.writeLine("cannot find parent mode by id: " + id)     
        }
        void
    }

    onBack() {
        forestScene.animateLookAt(vec3(0.0f, 0.0f, -5.0f), 2000)
        menuController.onBackFromForest()
        void
    }
) { this }

forestController : heap forestController()