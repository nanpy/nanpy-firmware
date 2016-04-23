from path import Path

HEADER = '''
// Generated file, do not edit!

#define LONGEST_STRING_IN_INTDEFS_H  {0}

'''

TEMPLATE = '''
#ifdef {0}
    DEFINE({0})
#endif
'''


def main():
    firmware_path = Path(__file__).abspath().parent.parent
#     nanpy_path = path(__file__).abspath().parent.parent / 'nanpy'
    input_path = Path(__file__).abspath().parent / 'intdefs.txt'
    output_path = firmware_path / 'Nanpy' / 'generated_intdefs.h'

    print('reading: %s' % input_path)
    print('writing: %s' % output_path)

    lines = [x.strip() for x in input_path.text().splitlines()]

    max_len = max([len(x) for x in lines])
    output = HEADER.format(max_len)
    for line in lines:
        output += TEMPLATE.format(line)

    output_path.write_text(output)

    print('done')

if __name__ == '__main__':
    main()
