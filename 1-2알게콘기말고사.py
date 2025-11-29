#정렬 : 자료를 다양한 기준(크기, 순서 등등)에 맞춰 순서대로 나열하는 작업
#정렬의 이점 : 자료를 쉽고 빠르게 찾을 수 
#정렬절차 : 기준 정하기 -> 자료 비교하기 -> 자료 이동시키기
#정렬효율성 : 1. 얼마나 많은 비교 2. 얼마나 많은 이동 에 따라 평가

#정렬 : 버블정렬 = 이웃한 자료 비교 -> 대소비교 -> 왼쪽기준 오른쪽값이 작으면 앞쪽으로 이동시키기
#정렬 : 선택정렬 = 최소값을 찾아 왼쪽부터 순서대로 정렬 (최소값 선택 -> i번째{0~len - 1}에 순차대로 자리 바꾸기)
#정렬 : 삽입정렬 = 정렬부분 / 비정렬부분 -> 비정렬부분의 왼쪽 부분을 적절한 위치에 삽입

arr = []

while True:
    arr_input = int(input("arr 입력값 : , -1은 종료"))
    if (arr_input == -1):
        break
    arr.append(arr_input)
    
def bubble_sort(arr):
    for i in range(len(arr) - 1, 0, -1): #첫번째 반복문에서의 반복변수는 다음반복문의 회전횟수를 위한 것
        for j in range(0, i, 1): #마지막 인덱스와 마지막 + 1 인덱스는 비교불가이므로 반복횟수는 배열개수 -1개로 지정
            if arr[j] > arr[j + 1]:
                temp = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = temp
    return arr

def selection_sort(arr):
    for k in range(0, len(arr), 1):
        swap_index_left = k
        for sel_index in range(k+1, len(arr)):
            if (arr[swap_index_left] > arr[sel_index]):
                swap_index_left = sel_index
        temp = arr[k]
        arr[k] = arr[swap_index_left]
        arr[swap_index_left] = temp
    return arr

def insert_sort(arr):
    #인덱스는 1부터 시작
    for k in range(1, len(arr)):
        temp = arr[k]
        j = k - 1
        
        while j >=0 and arr[j] > temp:
            arr[j+1] = arr[j] # 정렬/비정렬 기준구역 기준 왼쪽구역이 기준구역보다 크다는 것은 기준구역이 왼쪽구역보다 작다는 의미이므로 계속해서 스왑이 이뤄짐
            j -= 1
        arr[j+1] = temp # 맨처음 저장한 temp가 자신이 들어가야 할 공간으로 들어감
    return arr

print(f"버블 정렬 전 배열 : {arr}")
#(printf"버블 정렬 후 배열 : {bubble_sort(arr)}")
#print(f"선택 정렬 후 배열 : {selection_sort(arr)}")
print(f"삽입 정렬 후 배열 : {insert_sort(arr)}")
