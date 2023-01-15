# Exercise 1 - Cache Practice Problems

```c
/* Assume that each value in array is initalized to 5
Declaration and initialization of `array` omitted */

void accessWords(int array_size, int step_size, int rep_count, int option) {
    for (int k = 0; k < rep_count; k++) { 
        for (int index = 0; index < array_size; index += step_size) {
            if (option == 0) {
                // Option 0: One cache access - write
                array[index] = 0; 
            } else {
                // Option 1: Two cache accesses - read AND write
                array[index] = array[index] + 1; 
            }
        }
    }
}

int main() {
    int array_size = 32;
    int step_size = 8;
    int rep_count = 4;
    int option = 0;
    accessWords(array_size, step_size, rep_count, option);
    return 0;
}
```

## Scenario 1

**Program Parameters**:

- **Array Size**: 32 ints
- **Step Size**: 8
- **Rep Count**: 4
- **Option**: 0

**Cache Parameters**:

- **Cache Levels**: 1
- **Block Size**: 8 bytes
- **Number of Blocks**: 4
- **Associativity**: 1 (Direct Mapped)
- **Block Replacement Policy**: LRU

The layout of the cache can be seen here:

<table>
  <thead>
    <tr>
      <th>Valid</th>
      <th>Tag</th>
      <th colspan="2">Data</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>0</td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
    <tr>
      <td>0</td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
    <tr>
      <td>0</td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
    <tr>
      <td>0</td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
    <tr>
      <td colspan="2"></td>
      <td>Bytes 7-4</td>
      <td>Bytes 3-0</td>
    </tr>
  </tbody>
</table>

#### Compute the Byte Addresses

- \#offset bits = log2(block size) = log2(8) = 3

- \#index bits = log2(num indicies) = log2(4) = 2

- \#tag bits = # address bits - # index bits - # offset bits = 32 - 3 - 2 = 27

### Access Element 0

Byte Address: 0b 0000 0000 0000 0000 0000 0000 0000 0000

| Tag                                  | Index | Offset |
| ------------------------------------ | ----- | ------ |
| 0b 0000 0000 0000 0000 0000 0000 000 | 0b00  | 0b000  |

<table>
  <thead>
    <tr>
      <th>Valid</th>
      <th>Tag</th>
      <th colspan="2">Data</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>1</td>
      <td>0x0000000</td>
      <td>5</td>
      <td>0</td>
    </tr>
    <tr>
      <td>0</td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
    <tr>
      <td>0</td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
    <tr>
      <td>0</td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
    <tr>
      <td colspan="2"></td>
      <td>Bytes 7-4</td>
      <td>Bytes 3-0</td>
    </tr>
  </tbody>
</table>

### Access Element 8

Byte Address: 32 = 0b 0000 0000 0000 0000 0000 0000 0010 0000

| Tag                                  | Index | Offset |
| ------------------------------------ | ----- | ------ |
| 0b 0000 0000 0000 0000 0000 0000 001 | 0b00  | 0b000  |

<table>
  <thead>
    <tr>
      <th>Valid</th>
      <th>Tag</th>
      <th colspan="2">Data</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>1</td>
      <td>0x0000001</td>
      <td>5</td>
      <td>0</td>
    </tr>
    <tr>
      <td>0</td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
    <tr>
      <td>0</td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
    <tr>
      <td>0</td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
    <tr>
      <td colspan="2"></td>
      <td>Bytes 7-4</td>
      <td>Bytes 3-0</td>
    </tr>
  </tbody>
</table>

### Access Element 16

Byte Address: 64 = 0b 0000 0000 0000 0000 0000 0000 0100 0000

| Tag                                  | Index | Offset |
| ------------------------------------ | ----- | ------ |
| 0b 0000 0000 0000 0000 0000 0000 010 | 0b00  | 0b000  |

<table>
  <thead>
    <tr>
      <th>Valid</th>
      <th>Tag</th>
      <th colspan="2">Data</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>1</td>
      <td>0x0000002</td>
      <td>5</td>
      <td>0</td>
    </tr>
    <tr>
      <td>0</td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
    <tr>
      <td>0</td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
    <tr>
      <td>0</td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
    <tr>
      <td colspan="2"></td>
      <td>Bytes 7-4</td>
      <td>Bytes 3-0</td>
    </tr>
  </tbody>
</table>

### Access Element 24

Byte Address: 96 = 0b 0000 0000 0000 0000 0000 0000 0110 0000

| Tag                                  | Index | Offset |
| ------------------------------------ | ----- | ------ |
| 0b 0000 0000 0000 0000 0000 0000 011 | 0b00  | 0b000  |

<table>
  <thead>
    <tr>
      <th>Valid</th>
      <th>Tag</th>
      <th colspan="2">Data</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>1</td>
      <td>0x0000003</td>
      <td>5</td>
      <td>0</td>
    </tr>
    <tr>
      <td>0</td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
    <tr>
      <td>0</td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
    <tr>
      <td>0</td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
    <tr>
      <td colspan="2"></td>
      <td>Bytes 7-4</td>
      <td>Bytes 3-0</td>
    </tr>
  </tbody>
</table>