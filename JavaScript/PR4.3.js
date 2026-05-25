function truncate(str, maxlength) {
  if (str.length > maxlength) {
    return str.slice(0, maxlength - 1) + "…"
  }

  return str
}
alert(truncate("Що я хотів би розповісти на цю тему:", 20))
alert(truncate("Всім привіт!", 20))