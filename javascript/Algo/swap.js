const swap = (num1 , num2) =>{
    let temp ;
    temp = num1;
    num1 = num2;
    num2 = temp;
    return console.log("new swapped values:" + num1 + " and " + num2);
}
swap(4,5);
