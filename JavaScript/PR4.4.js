function strikeStr(str) {
  let words = str.split(" ")
  let result = ""

  for (let i = 0; i < words.length; i++) {
    result += words[i] + " "

    if ((i + 1) % 3 === 0) {
      result += "\n"
    }
  }

  return result.trim()
}
alert(strikeStr("Що я би хотів розповісти на цю тему: "))
alert(strikeStr("Всім привіт!"))