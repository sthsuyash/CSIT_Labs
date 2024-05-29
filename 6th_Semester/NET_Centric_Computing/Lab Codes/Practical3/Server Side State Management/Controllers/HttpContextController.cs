using Microsoft.AspNetCore.Http.Extensions;
using Microsoft.AspNetCore.Mvc;
using System.Web;

namespace Server_Side_State_Management.Controllers
{
    public class HttpContextController : Controller
    {
        public string Index()
        {
            string URL = HttpContext.Request.GetDisplayUrl();
            return URL;
        }

        /*
         * Return current timestamp
         */
        public string StatusCode()
        {
            return HttpContext.Response.StatusCode.ToString();
        }
    }
}
