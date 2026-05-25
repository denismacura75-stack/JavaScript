function recursiveSum(n) {
  if (n === 0) {
    return 0
  }

  if (n > 0) {
    return n + recursiveSum(n - 1)
  } else {
    return n + recursiveSum(n + 1)
  }
}
alert(recursiveSum(5));
alert(recursiveSum(-3));