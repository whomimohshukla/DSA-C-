// // const numbers = [1, 2, 3, 4, 5];

// // // numbers.forEach(n => console.log(n));

// // // const doubled = numbers.map(n => n * 2);

// // // console.log(doubled);


// // // const even = numbers.filter(n => n % 2 === 0);
// // // // [2, 4]

// // // console.log(even)

// // // const originalUser = {
// // //     name: "Mimoh",
// // //     address: { city: "Meerut" }
// // // };

// // // const copy = { ...originalUser, address: { city: "fubai" } };


// // // console.log(copy)


// // //rest 


// // // function sum(...args) {
// // //     return args.reduce((acc, curr) => acc + curr, 0);
// // // }

// // // console.log(sum(1, 2, 3, 4, 5)); // Output: 15

// // // const userData = {};

// // // // console.log(userData.address?.city); // undefined

// // // const username = userData.name ?? "Guest";
// // // console.log(username); // Guest

// // const objed={};


// // const userName=objed.name??"Guest";
// // console.log(userName); // Guest


// const newPromise = new Promise((resolve, reject) => {
//     const success = true;
//     if (success) {
//         resolve("Promise resolved successfully");
//     } else {
//         reject("Promise rejected");
//     }
// });


// newPromise
//     .then(result => {
//         console.log(result); // Output: Promise resolved successfully
//     })
//     .catch(error => {
//         console.error(error);
//     });



const fetchData = async () => {
    try {
        const response = await fetch('https://jsonplaceholder.typicode.com/posts/1');
        if (!response.ok) {
            throw new Error('Network response was not ok');
        }
        const data = await response.json();
        console.log(data);
    } catch (error) {
        console.error('Error fetching data:', error);
    }
}