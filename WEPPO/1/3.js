for (var i = 2; i <= 100000; i++) {
    var status = true;
    for (var j = 2; j * j <= i; j++) {
        if ((i % j) === 0) {
            status = false;
            break;
        }
    }
    if (status) {
        console.log(i);
    }
}