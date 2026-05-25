// ======= SELECT ELEMENTS =======
const form = document.querySelector(".grocery-form")
const alert = document.querySelector(".alert")
const grocery = document.getElementById("grocery")
const submitBtn = document.querySelector(".submit-btn")
const container = document.querySelector(".grocery-container")
const list = document.querySelector(".grocery-list")
const clearBtn = document.querySelector(".clear-btn")
// ======= EDIT OPTIONS =======
let editElement
let editFlag = false
let editID = ""
// ======= EVENTS =======
form.addEventListener("submit", addItem)
clearBtn.addEventListener("click", clearItems)
// ======= PAGE LOAD =======
window.addEventListener("DOMContentLoaded", setupItems)
// ======= ADD ITEM =======
function addItem(e) {
  e.preventDefault()
  const value = grocery.value
  if (value !== "" && !editFlag) {
    // create id
    const id = new Date().getTime().toString()
    // create article
    const element = document.createElement("article")
    element.classList.add("grocery-item")
    // add id
    element.setAttribute("data-id", id)
    // add HTML
    element.innerHTML = `
        <p class='title'>${value}</p>

        <div class='btn-container'>

          <button type="button" class='edit-btn'>
            <i class='fas fa-edit'></i>
          </button>

          <button type="button" class='delete-btn'>
            <i class='fas fa-trash'></i>
          </button>

        </div>
    `
    // buttons
    const deleteBtn = element.querySelector(".delete-btn")
    const editBtn = element.querySelector(".edit-btn")
    deleteBtn.addEventListener("click", deleteItem)
    editBtn.addEventListener("click", editItem)
    // append item
    list.append(element)
    // show container
    container.classList.add("show-container")
    // alert
    displayAlert("Продукт додано", "success")
    // save local storage
    addToLocalStorage(id, value)
    // reset
    setBackToDefault()
  }
  // ===== EDIT ITEM =====
  else if (value !== "" && editFlag) {
    editElement.textContent = value
    displayAlert("Продукт змінено", "success")
    // local storage
    editLocalStorage(editID, value)
    setBackToDefault()
  } else {
    displayAlert("Введіть значення", "danger")
  }
}
// ======= DISPLAY ALERT =======
function displayAlert(text, action) {
  alert.textContent = text
  alert.classList.add(`alert-${action}`)
  setTimeout(() => {
    alert.textContent = ""
    alert.classList.remove(`alert-${action}`)
  }, 1500)
}
// ======= DELETE ITEM =======
function deleteItem(e) {
  const element = e.currentTarget.parentElement.parentElement
  const id = element.dataset.id
  list.removeChild(element)
  if (list.children.length === 0) {
    container.classList.remove("show-container")
  }
  displayAlert("Продукт видалено", "danger")
  setBackToDefault()
  removeFromLocalStorage(id)
}
// ======= EDIT ITEM =======
function editItem(e) {
  const element = e.currentTarget.parentElement.parentElement
  // set edit item
  editElement = element.querySelector(".title")
  // display value
  grocery.value = editElement.textContent
  editFlag = true
  editID = element.dataset.id
  submitBtn.textContent = "Редагувати"
}
// ======= CLEAR ITEMS =======
function clearItems() {
  const items = document.querySelectorAll(".grocery-item")
  items.forEach((item) => {
    list.removeChild(item)
  })
  container.classList.remove("show-container")
  displayAlert("Список очищено", "danger")
  setBackToDefault()
  localStorage.removeItem("list")
}
// ======= DEFAULT SETTINGS =======
function setBackToDefault() {
  grocery.value = ""
  editFlag = false
  editID = ""
  submitBtn.textContent = "Додати"
}
// ======= LOCAL STORAGE =======
function addToLocalStorage(id, value) {
  const grocery = { id, value }
  let items = getLocalStorage()
  items.push(grocery)
  localStorage.setItem("list", JSON.stringify(items))
}
function getLocalStorage() {
  return localStorage.getItem("list")
    ? JSON.parse(localStorage.getItem("list"))
    : []
}
function removeFromLocalStorage(id) {
  let items = getLocalStorage()
  items = items.filter((item) => item.id !== id)
  localStorage.setItem("list", JSON.stringify(items))
}
function editLocalStorage(id, value) {
  let items = getLocalStorage()
  items = items.map((item) => {
    if (item.id === id) {
      item.value = value
    }
    return item
  })
  localStorage.setItem("list", JSON.stringify(items))
}
// ======= SETUP ITEMS =======
function setupItems() {
  let items = getLocalStorage()
  if (items.length > 0) {
    items.forEach((item) => {
      createListItem(item.id, item.value)
    })
    container.classList.add("show-container")
  }
}
// ======= CREATE ITEM =======
function createListItem(id, value) {
  const element = document.createElement("article")
  element.classList.add("grocery-item")
  element.setAttribute("data-id", id)
  element.innerHTML = `
      <p class='title'>${value}</p>

      <div class='btn-container'>

        <button type="button" class='edit-btn'>
          <i class='fas fa-edit'></i>
        </button>

        <button type="button" class='delete-btn'>
          <i class='fas fa-trash'></i>
        </button>

      </div>
  `
  const deleteBtn = element.querySelector(".delete-btn")
  const editBtn = element.querySelector(".edit-btn")
  deleteBtn.addEventListener("click", deleteItem)
  editBtn.addEventListener("click", editItem)
  list.append(element)
}