output = [];
var count = 1;

function fizzBuzz(){
    if(count % 3 === 0 && count % 5 !== 0){
        output.push("Fizz");
    }
    else if(count % 5 ===  0 && count % 3 !== 0){
        output.push("Buzz");
    }
    else if(count % 3 === 0 && count % 5 === 0){
        output.push("FizzBuzz");
    }
    else{
        output.push(count);
    }
    
    console.log(output);
    count++;
}
var noOfTimes = 0;
var n = 6;
while(noOfTimes < n){
    fizzBuzz();
    noOfTimes += 1;
}
