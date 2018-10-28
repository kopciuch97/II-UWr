for (var i = 1; i <= 100000; i++) {
    var x = i.toString()
                .split("")
                    .map(function (digits) {
                        return parseInt(digits)
                    });
    var status = true;
    for (var j = 0; j < x.length; j++) {
        if (x[j] !== 0) {
            if (i % x[j] !== 0) {
                status = false;
                break;
            }
        }
    }
    if (status && (i % x.reduce((a, b) => a + b)) === 0) {
        console.log(i);
    }
}