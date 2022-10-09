type _Node = {
  data: number|null,
  next: _Node|null
};

interface List {
  head: _Node
}

const createNode: (data: number|null) => _Node = function(data: number|null) {
  return {
    data: data,
    next: null
  }
}

const createList: () => List = function() {
  const node = createNode(null);

  return {
    head: node,
  }
}

const addNodeToList: (node: _Node, list: List) => List = function(node: _Node, list: List) {
    let next: _Node|null = list.head;

    if (list.head.data === null) {
        list.head = node;

        return list;
    }

    while (true) {
        if (next.next === null) {
            break;
        }

        next = next.next;
    }

    next.next = node;

    return list;
}

const showListElements = function(list: List) {
  let next: _Node|null = list.head;

  while(next !== null) {
    console.log(next.data);

    next = next.next;
  }
}

const node = createNode(23);
const nodeTwo = createNode(34);
const nodeThree = createNode(17);
const nodeFour = createNode(29);
const nodeFive = createNode(97);

let list = createList();
list = addNodeToList(node, list);
list = addNodeToList(nodeTwo, list);
list = addNodeToList(nodeThree, list);
list = addNodeToList(nodeFour, list);
list = addNodeToList(nodeFive, list);

console.clear();

showListElements(list);
