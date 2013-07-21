#include "pebble_os.h"
#include "http.h"
#include "http-utils.h"

char* httpebble_error(int error_code) {
  if (error_code > 1000) {
    error_code -= 1000;
  }

  switch (error_code) {
    case HTTP_SEND_TIMEOUT:
      return "SEND TIMEOUT";
    break;
    case HTTP_SEND_REJECTED:
      return "SEND REJECTED";
    break;
    case HTTP_NOT_CONNECTED:
      return "NOT CONNECTED";
    break;
    case HTTP_BRIDGE_NOT_RUNNING:
      return "BRIDGE NOT RUNNING";
    break;
    case HTTP_INVALID_ARGS:
      return "INVALID ARGS";
    break;
    case HTTP_BUSY:
      return "BUSY";
    break;
    case HTTP_BUFFER_OVERFLOW:
      return "BUFFER OVERFLOW";
    break;
    case HTTP_ALREADY_RELEASED:
      return "ALREADY RELEASED";
    break;
    case HTTP_CALLBACK_ALREADY_REGISTERED:
      return "CALLBACK ALREADY REGISTERED";
    break;
    case HTTP_CALLBACK_NOT_REGISTERED:
      return "CALLBACK NOT REGISTERED";
    break;
    case HTTP_NOT_ENOUGH_STORAGE:
      return "NOT ENOUGH STORAGE";
    break;
    case HTTP_INVALID_DICT_ARGS:
      return "INVALID DICT ARGS";
    break;
    case HTTP_INTERNAL_INCONSISTENCY:
      return "INTERNAL INCONSISTENCY";
    break;
    case HTTP_INVALID_BRIDGE_RESPONSE:
      return "INVALID BRIDGE RESPONSE";
    break;
    case 400:
      return "Bad Request";
    break;
    case 401:
      return "Unauthorized";
    break;
    case 403:
      return "Forbidden";
    break;
    case 404:
      return "Not Found";
    break;
    case 405:
      return "Method Not Allowed";
    break;
  }

  if (error_code >= 500 && error_code < 600) {
    return "HTTP Server Error";
  }
  else if (error_code > 400 && error_code < 500) {
    return "HTTP Client Error";
  }
  else if (error_code > 300 && error_code < 300) {
    return "HTTP Redirection";
  }

  return "Unknown Error";
}
