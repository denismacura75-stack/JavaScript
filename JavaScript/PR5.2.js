function sumInput() {
  let numbers = []

  while (true) {
    let value = prompt("Введіть число:")
    if (value === null || value === "" || !isFinite(value)) {
      break;
    }

    numbers.push(+value);
  }
  let sum = 0
  for (let number of numbers) {
    sum += number
  }
  return sum;
}
alert(sumInput())