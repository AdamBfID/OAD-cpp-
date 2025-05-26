import pandas as pd

#LOW DIM PROBLEMS
instances = [i for i in range(1, 11)]
capacities = [269,878,20,11,375,60,50,10000,80,879]
def print_cpp_vector(gains, weights, capacity):
    print("vector<vector<int>> TC = {")
    print("    // gains")
    print("    {", ", ".join(map(str, gains)), "},")
    print("    // weights")
    print("    {", ", ".join(map(str, weights)), "}")
    print("};")
    print("int maxWeight =", capacity, ";")
    print()
for i, k in enumerate(instances):
    file_name = f"/prob-{k}-low.csv"
    df = pd.read_csv(file_name)

    profits = df['Profit'].tolist()
    weights = df['Weight'].tolist()

    if i < len(capacities):
        print_cpp_vector(profits, weights, capacities[i])



#LARGE SCALE PROBLEMS
instances = [
    (1, 10000), (1, 1000), (1, 100), (1, 2000), (1, 200), (1, 5000), (1, 500),
    (2, 10000), (2, 1000), (2, 100), (2, 2000), (2, 200), (2, 5000), (2, 500),
    (3, 10000), (3, 1000), (3, 100), (3, 2000), (3, 200), (3, 5000), (3, 500)
]
capacities = [49877,5002,995,10011,1008,25016,2543,49877,5002,995,10011,1008,25016,2543,49519,4990,997,9819,997,24805,2517]


def print_cpp_vector(gains, weights, capacity):
    print("vector<vector<int>> TC = {")
    print("    // gains")
    print("    {", ", ".join(map(str, gains)), "},")
    print("    // weights")
    print("    {", ", ".join(map(str, weights)), "}")
    print("};")
    print("int maxWeight =", capacity, ";")
    print()


for i, (prefix, size) in enumerate(instances):
    file_name = f"knapPI_{prefix}_{size}_1000_1.csv"
    df = pd.read_csv(file_name)

    profits = df['Profit'].tolist()
    weights = df['Weight'].tolist()

    if i < len(capacities):
        print_cpp_vector(profits, weights, capacities[i])

