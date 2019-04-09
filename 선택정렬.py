def find_smallest(arr):
    smallest =arr[0] #최소값 초기화
    smallest_index=0# 최소값 인덱스 초기화
    for i in range(1,len(arr)):
        if arr[i]< smallest:# 최소값을 찾으면
            smallest=arr[i] #최소값 설정
            smallest_index =i #최소값에 해당하는 인덱스
    return smallest_index  # 최소값에 해당되는 인덱스를 반환
def selection_sort(arr):# arr : 배열을 매개변수로 입력 받음
    newArr=[] #새로운 배열 생성
    for i in range(len(arr)): #0,len(arr)-1 만큼 반복합니다
        smallest =find_smallest(arr) #최소값에 해당되는 인덱스을 찾습니다.
        newArr.append(arr.pop(smallest))#최소값을 배열에 넣습니다.
    return newArr # 선택정렬된 배열을 반환
myArr=[5,3,6,2,10]
selection_sort(myArr)