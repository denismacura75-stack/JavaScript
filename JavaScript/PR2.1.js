let user = {};
user.name = "Марк";
user.surname = "Сміт";
user.name = "Тарас";
delete user.name;
alert(JSON.stringify(user))