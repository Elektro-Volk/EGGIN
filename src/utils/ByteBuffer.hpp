class ByteBuffer {
  char *data;
  int pos;
  int size;
public:
  ByteBuffer(char *data, int size)
  {
    this->data = data;
    this->size = size;
    pos = 0;
  }
  ByteBuffer(int size)
  {
    this->data = (char*)malloc(size);
    this->size = size;
    pos = 0;
  }

  int getSize() { return size; }
  const char* getData()
  { return data; }
  void flushPos() { pos = 0; }
  // Read functions
  char readByte() { return data[pos++]; }
  // Write functions
  void writeByte(char byte)
  {
    if(pos + 1 >= size) {
      data = size == 0 ? (char*)malloc(1) : (char*)realloc(data, size + 1);
      size++;
    }
    data[pos++] = byte;
  }
  void writeBytes(char* bytes, int count)
  {
    if(pos + count >= size) {
      data = size == 0 ? (char*)malloc(count) : (char*)realloc(data, size  + count);
      size += count;
    }
    for(int i =0; i<count; i++)
  	data[pos++] = bytes[i];
  }
};
