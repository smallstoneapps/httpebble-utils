# Httpebble Utils

A collection of utility functions to be used when writing [Pebble][3] apps using [Katharine][2]'s [httpebble library][1].

### Error Message

Returns a string containing the error message for the given error code.

```c
char* httpebble_error(int error_code)
```

#### Sample Usage

```c
void http_failure(int32_t request_id, int http_status, void* context) {
  httpebble_error(http_status);
}
```
```c
HTTPResult  result = http_out_get("http://api.pblweb.com/tutorials/demo.php", HTTP_COOKIE, &dict);
if (result != HTTP_OK) {
  httpebble_error(result);
  return;
}
````

[1]: http://kathar.in/httpebble
[2]: http://kathar.in/
[3]: http://getpebble.com
