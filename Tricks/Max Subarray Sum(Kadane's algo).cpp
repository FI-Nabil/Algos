
 ll max_so_far = -inf, max_end_here = 0;
    for (ll i = 1; i <= n; i++) {
        max_end_here += a[i];
        if (max_end_here > max_so_far) max_so_far = max_end_here;
        if (max_end_here < 0) max_end_here = 0;
    }
return max_so_far;
