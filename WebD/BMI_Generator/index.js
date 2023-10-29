const form = document.querySelector('form');

form.addEventListener('submit', function(e) {
    //to stop the form's default action of going to the server
    e.preventDefault();

    //to get the values of name, height and weight
    const name = document.querySelector('#userName').value
    const height = parseInt(document.querySelector('#userHeight').value)
    const weight = parseInt(document.querySelector('#userWeight').value)
    const results = document.querySelector('#results')

    if(height < 0 || isNaN(height)) {
        results.innerHTML = "Please enter a proper height!"
    }
    else if(weight < 0 || isNaN(weight)) {
        results.innerHTML = "Please enter a proper weight!"
    }
    else {
        const bmi = (weight / ((height*height)/10000)).toFixed(2);
        // display result
        if(bmi < 18.6) {
            results.innerHTML = `<span>Hey ${name}, your BMI is ${bmi}. You are under weight.</span>`;
        }
        else if(bmi >= 18.6 && bmi <= 24.9) {
            results.innerHTML = `<span>Hey ${name}, your BMI is ${bmi}. Your weight is normal.</span>`;
        }
        else {
            results.innerHTML = `<span>Hey ${name}, your BMI is ${bmi}. You are over weight.</span>`;
        }
    }
});