function isPalindrome(word) {
    // Remove non-alphanumeric characters and convert to lowercase
    const cleanedWord = word.replace(/[^a-z0-9]/gi, '').toLowerCase();

    // Compare the cleaned word with its reverse
    return cleanedWord === cleanedWord.split('').reverse().join('');
}

const wordToCheck = "racecar"; // Change this to the word you want to check
if (isPalindrome(wordToCheck)) {
    console.log(`"${wordToCheck}" is a palindrome.`);
} else {
    console.log(`"${wordToCheck}" is not a palindrome.`);
}
