function checkSpam(str) {
  let lowerStr = str.toLowerCase()

  return lowerStr.includes('росі') || lowerStr.includes('xxx')
}
alert(checkSpam("поїхати до росії"))
alert(checkSpam("free xxxxx"))
alert(checkSpam("innocent rabbit"))