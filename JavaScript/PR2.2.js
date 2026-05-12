function isEmpty(obj) {
    for (let key in obj) {
        return false;
    }
    return true;
}
let user = {};
alert(isEmpty(user));
user.name = "Тарас";
alert(isEmpty(user));