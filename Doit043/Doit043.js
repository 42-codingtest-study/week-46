//문제: 1850
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
    function gcd(a, b) {
        return b == 0n ? a : gcd(b, a % b);
    }
    let [a, b] = input[0].split(" ").map(BigInt);
    let k = gcd(a, b);
    //   console.log(k);
    let result = "1";
    if (k >= 2n) {
        for (let a = 2n; a <= k; a++) {
            result += "1";
        }
    }
    console.log(result);
}
