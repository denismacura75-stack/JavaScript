function areAllUnique(arr) {
  let uniqueValues = new Set(arr)
  return uniqueValues.size === arr.length
}
const uniqueArray = [1, 2, 3, 4, 5]
const hasDuplicates = areAllUnique(uniqueArray)
console.log(hasDuplicates)
const arrayWithDuplicates = [1, 2, 3, 2, 4, 5]
const hasDuplicates2 = areAllUnique(arrayWithDuplicates)
console.log(hasDuplicates2)