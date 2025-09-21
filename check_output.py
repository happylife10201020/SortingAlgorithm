def read_input(filename="input.txt"):
    with open(filename, "r") as f:
        lines = f.readlines()
        length = int(lines[0].strip())
        arr = list(map(int, lines[1].strip().split()))
        if len(arr) != length:
            raise ValueError("input.txt의 데이터 개수가 길이와 일치하지 않습니다.")
        return arr

def read_output(filename="output.txt"):
    with open(filename, "r") as f:
        lines = f.readlines()
        if len(lines) < 3:
            raise ValueError("output.txt에 세 가지 정렬 결과가 모두 없습니다.")
        return {
            "Insertion Sort": list(map(int, lines[0].strip().split())),
            "Merge Sort": list(map(int, lines[1].strip().split())),
            "Merge-Insertion Sort": list(map(int, lines[2].strip().split()))
        }

def check_correctness(original, sorted_result, label):
    expected = sorted(original)
    if expected == sorted_result:
        print(f"✅ {label}: 정렬 결과가 정확합니다.")
    else:
        for i in range(len(expected)):
            if i >= len(sorted_result) or expected[i] != sorted_result[i]:
                print(f"❌ {label}: index {i}에서 틀림 → 예상 {expected[i]}, 결과 {sorted_result[i]}")
                return
        print(f"❌ {label}: 길이가 다릅니다. 예상 {len(expected)}개, 결과 {len(sorted_result)}개")

def main():
    input_data = read_input()
    output_data = read_output()

    for label in output_data:
        check_correctness(input_data, output_data[label], label)

if __name__ == "__main__":
    main()
