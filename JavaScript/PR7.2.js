function count(obj) {
  return Object.keys(obj).length
}
let user = {
  name: "Іван",
  age: 30
}
console.log(count(user))