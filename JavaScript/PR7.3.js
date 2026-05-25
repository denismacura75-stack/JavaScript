let user = {
  name: "Іван",
  years: 30
}
let {
  name,
  years: age,
  isAdmin = false
} = user
console.log(name)
console.log(age)
console.log(isAdmin)