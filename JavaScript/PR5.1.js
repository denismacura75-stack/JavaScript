let styles = ["Jazz", "Blues"]
styles.push("Rock-and-Roll")
let middleIndex = Math.floor(styles.length / 2)
styles[middleIndex] = "Classics"
let remove = styles.shift()
alert(remove)
styles.unshift("Rap", "Reggea")
alert(styles)