I just want to clarify that the only reason it is comparatively slow is because of what I decided to do. Since we fill out the vector from the start anyway and have to, what we could do 
is that we can come up with some algorithm where we can mark all spots on a board with some number, and that number will be the same for all spots along a diagonal because the intent
is to have those all those correspond to a marked diagonal. For example, if we have a spot that is taken by a queen, we can have some formula that will evaluate to 3 for all spots
along diagonals of that aforementioned spot through the use of the dependent x and y for that spot. We from there use the formula as indexing in our vector because vector supports
random access iteration and is filled out as mentioned in the beginning. This would drastically cut the search time in the algorithm as I seen mentioned by some online
as it will just evaluate to what that expression equals to as the x and y values dictate for that index in the vector, which is just a O(1) operation. I just did it this way because
I constructed the problem how I wanted to solve it, not necessarily going the most optimal route.
