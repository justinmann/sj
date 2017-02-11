include "common.sj"

console.write("Shall we play\n")

num : random.nextInt() % 10 + 1
isCorrect = false
guessCount = 0

while !isCorrect {
    guessCount ++
    str : console.readLine()
    guess : parse.toInt(str)
    isCorrect = if guess < num {
                    console.write("Too Low\n")
                    false
                } else if guess > num {
                    console.write("Too high\n")
                    false
                } else {
                    true
                }
}

console.write("Correct\n")
