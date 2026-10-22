//inversion of control 

// Definition: A callback is a function passed as an argument to another function so that the receiving function can execute it later or at a particular point.


// asyncFunc(somehting, function (eerr, data) {
//     if (eerr) {
//         //handle error
//     } else {
//         asyncFunc2(data, function (err, data2) {
//             if (err) {
//                 //handle error
//             } else {
//                 asyncFunc3(data2, function (err, data3) {
//                     if (err) {
//                         //handle error
//                     }

//                 )

loginUser("mohit", (user) => {
    getProfile(user.id, (profile) => {
        getOrders(profile.id, (orders) => {
            displayOrders(orders, () => {
                console.log("Orders displayed");
            });
        });
    });
});

// Readability: Every new operation adds another indentation level.

// Error handling: Each asynchronous operation needs a reliable error-handling path.

// Maintainability: Changing the sequence or adding another step becomes harder.

// Testing: Nested control flow can make individual steps and failure cases harder to test.

// Reusability: Business logic becomes tightly coupled to the callback structure.