void Lin2dBV(double out[], double in[], int n)
{
  unsigned long A, FSB;
  long out_log;
  double out_dB;
  unsigned short LSBIndex;

  long LUT[32] = {0, 1, 1, 2, 3, 3, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9,
                  9, 10, 10, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 15, 16};

  int i;

  for (i = 0; i < n; i++)
  {
    if (in[i])
    {
      A = (unsigned long)in[i];
      FSB = 5;
      if (A >= (1 << 5))
      {
        while (A >= (1 << 6))
        {
          FSB++;
          A >>= 1;
        }
      }
      else
      {
        while (A < (1 << 5))
        {
          FSB--;
          A <<= 1;
        }
      }
      LSBIndex = A - (1 << 5);

      out_log = (long)(FSB << 4) + LUT[LSBIndex];
      out_dB = (3 * out_log + 2) / 16.; // >> 4;
      out[i] = out_dB;
    }
    else
    {
      out[i] = -512.0;
    }
  }
}