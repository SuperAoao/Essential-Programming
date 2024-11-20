// In the given code snippet, the loop condition dataP < dataP + imgSize is incorrect. It will always evaluate to true because dataP is being compared with itself added to imgSize, which leads to an infinite loop and eventually causes an access violation.

// To fix this issue, the loop condition should be comparing dataP with the end of the data array, like this:

// cpp
// for (unsigned char* dataP = data; dataP < data + imgSize; ++dataP)
// {
//     float n_noise = std::max(std::round(noise(gen)), 0.0);
//     *dataP = n_noise / n_e;
// }
// By comparing dataP with data + imgSize, the loop will iterate through the data array without causing an access violation.