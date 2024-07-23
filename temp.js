function processData(input) {
    const lines = input.split('\n');

    const T = parseInt(lines[0]);

    const fixedCurrentTimeIST = new Date('2023-01-01T15:00:00+05:30');
    const fixedCurrentTimeUTC = new Date(fixedCurrentTimeIST.getTime() - (5.5 * 60 * 60 * 1000));

    function convertUtcToIst(utcTime) {
        const utcDate = new Date(utcTime);
        const istDate = new Date(utcDate.getTime() + (5.5 * 60 * 60 * 1000));
        return istDate;
    }

    function classifyContest(startUtc, endUtc) {
        const startIst = convertUtcToIst(startUtc);
        const endIst = convertUtcToIst(endUtc);

        if (fixedCurrentTimeIST >= startIst && fixedCurrentTimeIST <= endIst) {
            return "ONGOING";
        } else if (startIst.toDateString() === fixedCurrentTimeIST.toDateString() && startIst > fixedCurrentTimeIST) {
            return "UPCOMING";
        } else if (startIst > fixedCurrentTimeIST) {
            return "LATER";
        } else {
            return "NULL";
        }
    }

    let results = [];

    for (let i = 1; i <= T * 2; i += 2) {
        const startUtc = lines[i];
        const endUtc = lines[i + 1];
        results.push(classifyContest(startUtc, endUtc));
    }

    console.log(results.join('\n'));
}

process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function (input) {
    _input += input;
});

process.stdin.on("end", function () {
    processData(_input);
});
