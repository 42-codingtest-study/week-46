//문제: Doit037
//0. 문제 이해 :
//1. 시간 복잡도 확인:
//2. 적용 알고리즘 확인:
//3. 맞는 자료구조 확인: 소수를 구하는 로직 -> 에라토스테네스의 체 !
// 에라토스테네스의 체 로직
// 1) N까지의 일차원 배열을 만든다.
// 2) 2부터 N의 제곱근까지 수가 지워지지않은 수라면 본인의 배수(본인 빼고)들을 지운다.
// 3) 남은 것들은 소수!!!!!!!!!!!!!!!!!!
// -> 이거 만드는건 외워서 바로 나올 수 있게 해놓자!
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
    const [N, M] = input[0].split(" ").map(Number); //[3,6]
    const ERATOS = (n) => {
        const CHE = Array.from({ length: n + 1 }, () => 1);
        CHE[0] = 0;
        CHE[1] = 0;
        for (let i = 2; i * i <= n; i++) {
            if (!CHE[i]) continue;
            else {
                for (let div = i * 2; div <= n; div += i) {
                    //배수들 0으로 바꿔
                    CHE[div] = 0;
                }
            }
        }
        return CHE;
    }; //에토체 만들기
    const SOSU_M = ERATOS(M); // M까지의 소수 체
    for (let i = N; i <= M; i++) {
        // N~M까지 소수면 출력
        if (SOSU_M[i]) console.log(i);
    }
}
