//문제: Doit040
//0. 문제 이해 :
//1. 시간 복잡도 확인:
//2. 적용 알고리즘 확인:
//3. 맞는 자료구조 확인:
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
    const [min, max] = input[0].split(" ").map(Number);
    const RESULT = new Array(max - min + 1).fill(true);

    // max보다 작은 제곱수들 모두
    for (let i = 2; i ** 2 <= max; i++) {
        let k = Math.ceil(min / i ** 2); // min보다 크거나 같은 배수부터 시작해서
        for (let j = k * i ** 2; j <= max; j += i ** 2) {
            // max보다 작거나 같은 배수까지
            if (min <= j && j <= max) {
                RESULT[j - min] = 0; // 0으로 체크
            }
        }
    }

    // 지워지지 않고 true로 남아있는 수들은 제곱수의 배수가 아니므로 filter함수를 통해 길이를 구한다.
    const answer = RESULT.filter((a) => a == true).length;
    console.log(answer);
}
