# 그래프
### 01/10~

## Union Find
- 각 노드마다 연결된 1개의 노드가 주어질 때 트리를 구성하여 최상위 노드가 서로 같은 경우 같은 집단에 속함을 파악할 수 있다.
- 처음에는 모든 부모 노드를 자기 자신으로 초기화하고, 연결관계가 주어질 때 마다 union 함수를 이용하여 트리를 구성한다.
- find 함수를 이용하여 최상단 노드를 찾아주고, 경로 압축을 진행하여 수행 시간을 단축시켜 줍니다.

### find 함수
- 최상위 노드를 찾는다.
- A의 부모 노드를 반환한다.
- 경로를 압축한다.
- 두 노드의 find 함수 값이 같으면 서로 동일한 그룹에 속함을 알 수 있다.
- find(0) → return 5, 0 → 5, 2 → 5, 8 → 5

### union함수
- A와 B의 부모 노드를 연결한다.
- 경로 압축(find 함수 포함)

<br><br>


## 위상 정렬 Topological Sort

#### 비순환이면서 방향성을 가진 그래프에서 노드 간 진행 순서를 정렬하는 알고리즘

- 진행 순서에 따라 노드를 정렬하는 것을 의미한다
- 일반적으로 한 가지 이상의 결과가 나온다.
    - 퀘스트 수행 순서나 요리 순서와 비슷하다.
- 진행 순서대로 정렬하는 방법은?
    - 탐색 시작 노드(input이 없는 노드)를 큐에 저장하고 이로 부터 탐색한다.
    - 노드를 거치면 해당 노드의 input수를 1감소시킨다.(0이되면 탐색 시작 노드가 될 수 있다.)
- 원리
    - 각 노드마자 자신으로 향하는 노드의 개수를 저장한다.(indegree)
    - 탐색 노드에서 출발하여 도착하는 노드의 indegree를 하나씩 빼 줍니다.
    - indegree가 0이 되는 경우, 해당 노드에 도착하기 위한 전 단계를 모두 거쳤음을 의미한다.
        
        이를, queue에 저장하여 출발 노드로 이용한다.
        
    - queue가 빌때 까지 탐색을 진god한다.