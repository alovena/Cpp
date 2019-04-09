def select_sort(arr): #arr: 매개변수로 입력 받는 배열
    for i in range(0,len(arr)-1):
        least=i;#최소값은 첫번째 인덱스라고 가정
        for j in range(i+1,len(arr)):#첫번째 다음 인덱스부터 배열의 끝까지 비교하여 최소값을 찾음
            if(arr[j]<arr[least]): #최소값을 찾았다면
                least=j #현재 위치를 최소값 인덱스로 정하고
        temp=arr[i] #교환
        arr[i]=arr[least]
        arr[least]=temp
                
            
    return arr# 선택 정렬을 마친후 배열을 반환
arr=[5,1,2,4,3] #배열 arr
select_sort(arr) #선택정렬
print(arr) #결과