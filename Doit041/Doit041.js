//문제: Doit041
//0. 문제 이해 :
//1. 시간 복잡도 확인:
//2. 적용 알고리즘 확인:
//3. 맞는 자료구조 확인:
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
    let n = +input[0];
    // 오일러 파이 함수 공식 그냥 쓰기
    // 소인수만 찾으면 됨
    let answer = n;
    for (let i = 2; i * i <= n; i++) {
        if (!(n % i)) {
            answer -= Math.floor(answer / i);
            while (!(n % i)) {
                n = Math.floor(n / i);
            }
        }
    }
    if (n > 1) {
        answer -= Math.floor(answer / n);
    }
    console.log(answer);
}
