def find_smallest(arr):#최소값 찾는 함수
    smallest =arr[0] 
    smallest_index=0
    for i in range(1,len(arr)):
        if arr[i]< smallest:
            smallest=arr[i] 
            smallest_index =i 
    return smallest_index 
def selection_sort(arr):# arr : 배열을 매개변수로 입력 받음
    newArr=[]
    for i in range(len(arr)): #0,len(arr)-1 만큼 반복합니다
        smallest =find_smallest(arr) 
        newArr.append(arr.pop(smallest))
    return newArr 
myArr=[5,3,6,2,10]
selection_sort(myArr)
