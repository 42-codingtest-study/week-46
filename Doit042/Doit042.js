//문제: Doit042
//0. 문제 이해 :
//1. 시간 복잡도 확인:
//2. 적용 알고리즘 확인:
//3. 맞는 자료구조 확인:
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
    const [t, ...arr] = input;
    //유클리드 호제법을 사용한 최대공약수와 최소공배수 구하기
    const GCD = (a, b) => (a % b === 0 ? b : GCD(b, a % b));
    const LCM = (a, b) => (a * b) / GCD(a, b);
    const RESULT = [];

    for (let e of arr) {
        const [N, M] = e.split(" ").map(Number);
        RESULT.push(LCM(N, M));
    }

    console.log(RESULT.join("\n"));
}
